#pragma once

# include <iostream>
# include <initializer_list>
# include <memory>
# include <vector>

using namespace std;

class ObjectScene;

using PtrObjectScene = shared_ptr<ObjectScene>;
using VectorObjectScene = vector<PtrObjectScene>;

class ObjectScene
{
public:
	using value_type = ObjectScene;
	using size_type = size_t;
	using iterator = VectorObjectScene::const_iterator;
	using const_iterator = VectorObjectScene::const_iterator;

	virtual ~ObjectScene() = 0;

	virtual bool isComposite() const { return false; }
	virtual bool add(initializer_list<PtrObjectScene> comp) { (void)(comp); return false; }
	virtual bool remove(const iterator& it) { (void)(it); return false; }
	virtual iterator begin() const { return iterator(); }
	virtual iterator end() const { return iterator(); }
};
