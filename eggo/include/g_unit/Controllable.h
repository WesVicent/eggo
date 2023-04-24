/**
	created by: Wes Ferreira 2021-05-27
*/

#pragma once
#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H

namespace G {

	class Controllable {
	protected:

	public:
		void virtual allowMovements(MainWindow::EnabledKeys key) = 0;

		virtual ~Controllable() {};

	private:
	};
}

#endif // !CONTROLLABLE_H

