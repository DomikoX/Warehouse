#include "Menu.h"
#include "cli.h"


MenuI::MenuI(Cli *owner) :
	items_(new LinkedList<MenuItem*>()),
	owner_(owner)
{
	items_->add(new MenuItem("Exit",&Cli::endFcion));
}





MenuI::~MenuI()
{ 
	delete items_;
	items_ = nullptr;
}

void MenuI::addItem(const string& text, menuFcion menufcion)
{
	items_->add(new MenuItem(text, menufcion));
}

string MenuI::toString()
{
	string text = "";
	int i = 0;
	for (MenuItem *item : *items_) {
		text += to_string(i) + item->toString() + "\n";
		i++;
	}
	text += "Please enter a number: \n";
	return text;
}

void MenuI::runMenu()
{
	cout << toString();
	int result = owner_->getInteger(0, items_->size()-1);

		runItem(result);

		if (result != 0) {
			runMenu();
		}
	
}



void MenuI::runItem(int index)
{
	(*items_)[index]->run(owner_);

}

MenuI::MenuItem::MenuItem(const string& text, menuFcion fcion) :
	text_(text),
	fcion_(fcion)
{
	
}

const string& MenuI::MenuItem::toString()
{
	return text_;
}

void MenuI::MenuItem::run(Cli *owner)
{
	(owner->*fcion_)();
}



