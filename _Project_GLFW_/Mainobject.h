#pragma once
#include "Renderer.h"


class Object : public Renderer
{

private:
	std::string name;
	std::string path;

public:
	void objfileparser(const std::string& path, std::vector<float> Vertices, std::vector<unsigned int> Indices);
public:
	Object(const std::string& name, const std::string& path);
	
	const std::string& get_name()const;
	const std::string& get_path()const;

};
