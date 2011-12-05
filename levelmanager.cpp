#include "levelmanager.h"

#include <QDomDocument>
#include <QTextStream>
#include <QFile>

#include <iostream>

LevelManager::LevelManager()
{
}

QDomElement GameObjectToNode(QDomDocument& d, const GameObject& game_object)
{
  QDomElement node = d.createElement("object");

  node.setAttribute("type", game_object.class_name());
  node.setAttribute("X", game_object.offset_.x());
  node.setAttribute("Y", game_object.offset_.y());

  QDomElement body_node = d.createElement("body");
  node.appendChild(body_node);

  foreach(QPointF point, game_object.body_)
  {
    QDomElement point_node = d.createElement("point");
    point_node.setAttribute("X", point.x());
    point_node.setAttribute("Y", point.y());
    body_node.appendChild(point_node);
  }

  return node;
}

int LevelManager::WriteLevel(const QString& file_name, const Level& level)
{
  QDomDocument doc("GameLevel");
  QDomElement root = doc.createElement(level.name_);
  doc.appendChild(root);

  foreach(GameObject* game_object, level.objects_)
    root.appendChild(GameObjectToNode(doc, *game_object));

  QFile file(file_name);

  if (!file.open(QIODevice::WriteOnly))
    return -1;

  QTextStream text_stream(&file);
  text_stream << doc.toString();

  file.close();

  return 0;
}

QPointF GetElementPoint(const QDomElement& element)
{
  return QPointF(element.attribute("X", "").toDouble(), element.attribute("Y", "").toDouble());
}

GameObject* StringToObject(QString class_name)
{
  if (class_name == "Reflector")
    return new Reflector();

  if (class_name == "Absorber")
    return new Absorber();

  if (class_name == "GameObject")
    return new GameObject();

  return NULL;
}

int LevelManager::ReadLevel(const QString& file_name, Level& level)
{
  QFile file(file_name);

  if (!file.open(QIODevice::ReadOnly))
    return -1;

  QDomDocument doc("GameLevel");
  if (!doc.setContent(&file))
  {
    file.close();
    return -2;
  }

  file.close();

  QDomElement root = doc.documentElement();

  level.name_ = root.tagName();

  QDomNode object_node =  root.firstChild();
  while (!object_node.isNull())
  {
    QDomElement object_element = object_node.toElement();

    if (!object_element.isNull())
    {
      GameObject *game_object = StringToObject(object_element.attribute("type", ""));

      if (!game_object)
        continue;

      game_object->offset_ = GetElementPoint(object_element);

      QDomNode body_node = object_node.firstChild();

      if (!body_node.isNull())
      {
        QDomNode point_node = body_node.firstChild();
        while (!point_node.isNull())
        {
          QDomElement point_element = point_node.toElement();
          if (!point_element.isNull())
            game_object->body_.push_back(GetElementPoint(point_element));

          point_node = point_node.nextSibling();
        }
      }

      level.objects_.push_front(game_object);
    }
    object_node = object_node.nextSibling();
  }

  return 1;
}

Level LevelManager::create_test_level()
{
  Level test_level;
  test_level.name_ = "Test_Level";
  int w = 200, h = 400;
  for(int i = 0; i < 5; i++)
  {
    GameObject* reflector = new Reflector();
    reflector->offset_ = QPointF(0.0, 0.0);
    for(int point_count = 0; point_count < 5; point_count++)
      reflector->body_.push_back(QPointF(qrand()%w, qrand()%h));
    test_level.objects_.push_back(reflector);
  }

//  GameObject* absorber = new Absorber();
//  absorber->center_ = QPointF(3.0, -1.0);
//  absorber->body_.push_back(QPointF(0, 240));
//  absorber->body_.push_back(QPointF(30, 130));
//  absorber->body_.push_back(QPointF(50, 230));

//  test_level.objects_.push_back(absorber);

  return test_level;
}
