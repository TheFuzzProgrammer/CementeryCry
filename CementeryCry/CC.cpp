#include "CC.h"
using namespace CementeryCry;

int main() {
	try {
		Application::Run(gcnew CC);
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message);
		return -1;
	}
	
}