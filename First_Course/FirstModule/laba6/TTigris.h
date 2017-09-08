//
// Created by Алексей Долматов on 21.03.17.
//

#ifndef MYZOO_TTIGRIS_H
#define MYZOO_TTIGRIS_H
#include "TCarnivora.h"
class TTigris :
	public TCarnivora
{
public:
	TTigris();

	TTigris(std::string const & name, size_t age);

	void Live(float time);

};


#endif //MYZOO_TTIGRIS_H
