#include "levelmanager.h"

#include <QDomDocument>
#include <QTextStream>
#include <QFile>

LevelManager::LevelManager()
{
}

QDomElement GameObjectToNode(QDomDocument& d, const GameObject& game_object)
{
  QDomElement node = d.createElement("object");

  node.setAttribute("type", game_object.class_name_);
  node.setAttribute("centerX", game_object.center_.x());
  node.setAttribute("centerY", game_object.center_.y());

  QDomElement body = d.createElement("body");
  node.appendChild(body);

  for(int i = 0; i < game_object.body_.size(); i++)
  {
    QDomElement point = d.createElement("point");
    point.setAttribute("X", game_object.body_.at(i).x());
    point.setAttribute("Y", game_object.body_.at(i).y());
    body.appendChild(point);
  }

  return node;
}

bool LevelManager::WriteLevel(const QString& file_name, const Level& level)
{
  QDomDocument doc("GameLevel");

  QDomElement root = doc.createElement(level.name_);
  doc.appendChild(root);

  foreach(GameObject game_object, level.objects_)
    root.appendChild(GameObjectToNode(doc, game_object));

  QFile file(file_name);

  if (!file.open(QIODevice::WriteOnly))
    return 0;

  QTextStream text_stream(&file);
  text_stream << doc.toString();

  file.close();

  return 1;
}

bool LevelManager::ReadLevel(const QString& file_name, Level& level)
{
  return 0;
}


bool LevelManager::GetLevel(int index, Level& level)
{
  return new Level();
}

void LevelManager::AddLevel(const Level& level)
{
}
