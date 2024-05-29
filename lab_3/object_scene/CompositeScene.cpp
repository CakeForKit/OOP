#include <CompositeScene.h>

CompositeScene::CompositeScene(PtrObjectScene first, ...)
{
	for (shared_ptr<ObjectScene>* ptr = &first; *ptr; ++ptr)
		vec.push_back(*ptr);
}

bool CompositeScene::add(initializer_list<PtrObjectScene> list)
{
	for (auto elem : list)
		vec.push_back(elem);

	return true;
}
