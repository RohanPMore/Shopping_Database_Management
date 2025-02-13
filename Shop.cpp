/*
 * Shop.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include <list>
#include <stdexcept>

#include "Shop.h"
#include "ShoppingList.h"
#include "Item.h"
#include "Discount.h"

using namespace std;

Shop::Shop(std::string name) : name{name} {
}

std::string Shop::getName() const {
	return name;
}

Shop& Shop::addProduct(const Product &product) {
	// TODO (add code)
	products.insert(std::pair<std::string, Product>(product.getName(), product));
	return *this;
}

Shop& Shop::setBasePrice(std::string productName, float basePrice) {
	// TODO (add code)
	std::map<std::string, Product>::iterator it;
    it = products.find(productName);
    if (it != products.end())
	  throw std::invalid_argument("The product is not available at shop");
    it->second.setBasePrice(basePrice);
	return *this;
}

Shop& Shop::setDiscount(std::string productName,
		std::shared_ptr<Discount> discount) {
	// TODO (add code)
	std::map<std::string, Product>::iterator it;
	it = products.find(productName);
    if (it != products.end())
	  throw std::invalid_argument("The product is not available at shop");
    it->second.setDiscount(discount);
	return *this;
}

float Shop::calculatePurchase(const ShoppingList& shoppingList,
		std::set<const Item*>& notAvailable) const {
	// TODO (add code/replace "dummy return")
	return 0;
}

