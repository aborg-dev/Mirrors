#include "levelmanager.h"

#include <QDomDocument>
#include <QFile>

LevelManager::LevelManager()
{
}

QDomElement GameObjectToNode(QDomDocument & d, const GameObject & game_object)
{
  QDomElement node = d.createElement("object");

  node.setAttribute("type", game_object.class_name_);
  node.setAttribute("centerX", game_object.center_.x());
  node.setAttribute("centerY", game_object.center_.y());

  for(int i = 0; i < game_object.skeleton_.size(); i++)
  {
    node.setAttribute("pointX_" + QString::number(i) , game_object.skeleton_.at(i).x());
    node.setAttribute("pointY_" + QString::number(i) , game_object.skeleton_.at(i).y());
  }

  return node;
}

bool LevelManager::WriteLevel(const QString & file_name, const Level &level)
{
  QDomDocument doc("GameLevel");
  QFile file(file_name);

  if (!file.open(QIODevice::WriteOnly))
    return 0;
  if (!doc.setContent(&file))
  {
    file.close();
    return 0;
  }

  QDomElement root = doc.createElement(level.name_);
  doc.appendChild(root);

  foreach(GameObject game_object, level.objects_)
    root.appendChild(GameObjectToNode(doc, game_object));

}

bool LevelManager::ReadLevel(const QString & file_name, Level &level)
{
}


bool LevelManager::GetLevel(int index, Level & level)
{
  return new Level();
}

void LevelManager::AddLevel(const Level &level)
{
}
