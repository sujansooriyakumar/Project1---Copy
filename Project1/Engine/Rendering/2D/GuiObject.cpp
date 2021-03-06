#include "GuiObject.h"
#include <iostream>

GuiObject::GuiObject(glm::vec3 position_)
{
	position = position_;
}

GuiObject::~GuiObject()
{
	if (guiComponents.size() > 0)
	{
		for (auto m : guiComponents)
		{
			m = nullptr;

		}
		guiComponents.clear();
	}
}

void GuiObject::Draw(Camera* camera)
{
	for (auto m : guiComponents) {
		m->Draw(camera, position);
	}
}

bool GuiObject::FindContainingPoints()
{
	
	for (auto m : guiComponents) {
		if(m->FindContainingPoint(position)) return true;
	}
	return true;
}

void GuiObject::SetTag(std::string tag_)
{
	tag = tag_;
}
