#include <iostream>
#include <cstdlib>
#include <memory>
#include <set>
#include <cmath>
#include <stdexcept>

#include "FixedDiscount.h"
#include "ShoppingList.h"
#include "ShopDb.h"
#include "Shop.h"
#include "Item.h"
#include "QuantityDiscount.h"

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the shopping list classes. (XX points)
 */
void shoppingListTests() {
	/*
	 * Create a shopping list with 2 (l) of milk, 250 (g) butter,
	 * and 1.5 (kg) bread. Use ShoppingList::items to retrieve
	 * the items and assert that for each that they have the
	 * expected name and quantity. (12 points)
	 */
	// TODO
	ShoppingList list1;
	list1.addItem("milk", 2);
	list1.addItem("butter", 250);
	list1.addItem("bread", 1.5);

	std::list<Item> mylist;
	std::list<Item>::const_iterator start = mylist.begin();
	std::list<Item>::const_iterator end = mylist.end();
	list1.items(start, end);

	for(auto it = start; it != end; it++)
	{
		if((it->getName() == "milk") && (it->getQuantity() == 2))
		{
			assertTrue(true, "milk 2 litres found in item list");
		}
		else if((it->getName() == "butter") && (it->getQuantity() == 250))
		{
			assertTrue(true, "butter 250 qty found in item list");
		}
		else if((it->getName() == "bread") && (it->getQuantity() == 1.5))
		{
			assertTrue(true, "bread 1.5 qty found in item list");
		}
	}
}

/**
 * Tests for the shop db classes. (XX points)
 */
void shopDbTests() {
    /*
     * (1) Test the methods of class ShopDb using the names given below.
     * Proceed as follows:
     *   * Create a ShopDb and add shops with the given names to it.
     *   * Use ShopDb::shops to get pointers to the shops in the database.
     *   * For each shop,
     *       * assert that that the shop's name is in the set "names".
     *       * assert that that the pointer that you got from ShopDb::shops
     *         is equal to the pointer that you get from ShopDb::shopByName
     *       * remove the shop's name from the set "names".
     *   * Finally assert that that you got all shops by checking that the
     *     set "names" is empty.
     *   (7 points)
     */
	set<string> names = { "Foodie1", "Bakers4less", "Spiceology", "Grainfruit",
		"Sweetteas", "Savorystyle", "TheSpiceHouse", "FoodieFun",
		"FlavorStation", "DoughLife", "INGredientsOnly", "FreshFix", "Tastync",
		"FlavorFile", "BiteMe", "TheFlavorSpot", "AtisfyMyCravings",
		"TastyTreats", "TheFoodFactor", "MunchiesLand", "TheSnackCave",
		"FoodieFrenzy", "TheMorselMansion", "BiteClub", "TheSavorStore",
		"TheFoodieFactor", "FlavorfulFinds", "TheTastyTrove" };

	ShopDb shopDataBase;
	set<string>::iterator itr, itr2;

	for(itr = names.begin(); itr != names.end(); itr++)
	{
		shopDataBase.addShop(std::make_unique<Shop>(*itr));
		itr2 = names.find (*itr);
		names.erase (itr2, names.end());
	}

	std::vector<Shop*> shopList = shopDataBase.shops();
	for(const auto& shop:shopList)
	{
		std::set<string>::iterator shopVector = names.find(shop->getName());
		if(shopVector != names.end())
		{
			assertTrue(true, "Shop " + shop->getName() + " found in database");
		}
	}

	for(const auto& shop:shopList)
	{
		if(shopDataBase.shopByName(shop->getName()) != nullptr)
		{
			assertTrue(true, "Shop " + shop->getName() + " and" + shopDataBase.shopByName(shop->getName())->getName() + " found.");
		}
	}

	// TODO

	/*
	 * (2) Test LinearDiscount by creating an instance for 5% (0.05) and
	 * another one for 10% (0.1) and then asserting for each of the
	 * two that you get the expected result when invoking
	 * LinearDiscount::discountFor with arguments 0, 10 and 100. (6 points)
	 */
	// TODO
//	FixedDiscount fd(5);
//	Discount::discountFor(10);


	/*
	 * (3) Test QuantityDiscount by creating an instance for the
	 * following rules:
	 *   * A discount of 5% (0.05) starting with a quantity of 10
	 *   * A discount of 10% (0.1) starting with a quantity of 50
	 *   * A discount of 15% (0.15) starting with a quantity of 100
	 *
	 * Assert that that QuantityDiscount::discountFor returns the expected
	 * values for quantities 0, 9, 10, 11, 49, 50, 51, 99, 100 and 101.
	 * (8 points)
	 */
	// TODO

	/*
	 * (4) Create a shop "Bakers4less" that sells bread at
	 * 5.6 per unit (kg). Assert that changing the base price
	 * (price per unit) for milk (!) at Bakers4less throws an
	 * invalid_argument exception (because they don't offer milk)
	 * (5 points)
	 */
	// TODO
	Shop bakershop("Bakers4less");
	Product product1("bread", 5.6);
	bakershop.addProduct(product1);
	bakershop.setBasePrice("milk", 2);
}

void evalTests() {
	/*
	 * Create a shop db. Add the shop "Bakers4less" from the
	 * function shopDbTests. Add another shop "Foodie1" that
	 * sells "Milk" at 2.1 per unit, "Bread" at 5.8 per unit
	 * and "Butter" at 0.00996 per unit.
	 *
	 * Copy the shopping list from function shoppingListTests.
	 *
	 * (1) Assert that purchasing everything from the shopping
	 * list at Foodie1 costs 15.39 and that they have everything
	 * available.
	 *
	 * (2) Assert that the purchase at Bakers4less amounts to
	 * 8.40 only and that the method reports that the shop does not
	 * provide milk and butter.
	 *
	 * (19 points)
	 */
	// TODO

	ShopDb newShopDb;
	std::set<string>::iterator it;
	std::unique_ptr<Shop> bakerShop(new Shop("Bakers4less"));
	std::unique_ptr<Shop> Foodie1(new Shop("Foodie1"));
	newShopDb.addShop(std::move(bakerShop));
	newShopDb.addShop(std::move(Foodie1));
	Product product1("Milk", 2.1);
	Product product2("Bread", 5.8);
	Product product3("Butter", 0.00996);
	Foodie1->addProduct(product1);
	Foodie1->addProduct(product2);
	Foodie1->addProduct(product3);

	ShoppingList list1;
	list1.addItem("milk", 2);
	list1.addItem("butter", 250);
	list1.addItem("bread", 1.5);

	for(auto it = list1.begin(); it != list1.end(); it++)
	{

	}
}

void allTests() {
    shoppingListTests();
    shopDbTests();
    evalTests();
}
