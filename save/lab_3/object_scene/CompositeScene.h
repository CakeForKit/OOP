#pragma once

#include <ObjectScene.h>

class CompositeScene : public ObjectScene
{
private:
	VectorObjectScene vec;

public:
	CompositeScene() = default;
	CompositeScene(PtrObjectScene first, ...);
	~CompositeScene() override = default;

	bool isComposite() const override { return true; }
	bool add(initializer_list<PtrObjectScene> list) override;
	bool remove(const iterator& it) override { vec.erase(it); return true; }
	iterator begin() const override { return vec.begin(); }
	iterator end() const override { return vec.end(); }
};
