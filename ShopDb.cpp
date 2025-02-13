/*
 * ShopDb.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include "ShopDb.h"
#include "Shop.h"

using namespace std;

ShopDb& ShopDb::addShop(std::unique_ptr<Shop>&& shop) {
	// TODO (add code)
	knownShops.insert(std::pair<std::string, std::unique_ptr<Shop>>(shop->getName(), std::move(shop)));
	return *this;
}

vector<Shop*> ShopDb::shops() const {
	// TODO (add code/replace "dummy return")
	std::vector<Shop*> shopList;

	for(const auto& pair:knownShops)
	{
		shopList.push_back(new Shop(*pair.second));
	}

	return shopList;
}

Shop* ShopDb::shopByName(std::string name) {
	// TODO (add code/replace "dummy return")
	std::map<std::string, std::unique_ptr<Shop>>::iterator it;
	it = knownShops.find(name);
	if(it != knownShops.end())
	{
		return std::move(it->second.get());
	}
	return nullptr;
}
