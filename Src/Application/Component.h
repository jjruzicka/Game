#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H
class Component
{
public:
	Component();
	virtual ~Component(){};
	virtual void Update() = 0;
};

#endif