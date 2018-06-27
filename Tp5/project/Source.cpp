#include "HighscoreManager.h"
#include "nana/gui.hpp"
#include "nana/gui/widgets/label.hpp"
#include "nana/gui/widgets/button.hpp"
#include <iostream>
using namespace std;

int main() {

	HighscoreManager* HSM = new HighscoreManager(5);

	HSM->AddScore("Lean", 80);
	HSM->AddScore("Ian", 100);
	HSM->AddScore("Persona", 50);
	HSM->AddScore("Sergio", 9999);
	HSM->AddScore("L", -1);

	using namespace nana;

	//Define a form.
	form fm;

	//Define a label and display a text.


	label lab{ fm , rectangle(50,50,100,100) };
	string txt = HSM->GetScore(1)->GetName() + "\t" + to_string(HSM->GetScore(1)->GetScore()) + "\n" +
				 HSM->GetScore(2)->GetName() + "\t" + to_string(HSM->GetScore(2)->GetScore()) + "\n" +
				 HSM->GetScore(3)->GetName() + "\t" + to_string(HSM->GetScore(3)->GetScore()) + "\n" +
				 HSM->GetScore(4)->GetName() + "\t" + to_string(HSM->GetScore(4)->GetScore()) + "\n" +
				 HSM->GetScore(5)->GetName() + "\t" + to_string(HSM->GetScore(5)->GetScore());
	lab.caption(txt);
	lab.format(true);

	//Define a button and answer the click event.
	button btn{ fm, "Quit" };
	btn.events().click([&fm] {
		fm.close();
	});

	//Layout management
	fm["text"] << lab;
	fm.collocate();

	//Show the form
	fm.show();

	//Start to event loop process, it blocks until the form is closed.
	exec();

	return 0;
}