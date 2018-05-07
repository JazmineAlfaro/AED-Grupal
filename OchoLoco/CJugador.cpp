#include "stdafx.h"
#include "CJugador.h"


//Se cambiado el constructor,ahora cuando se crea el jugador su puntación empieza con 0
//Se creo la funcion calcular puntuacion, esta se utilizara cuando ya no haya
CJugador::CJugador()
{
	puntuacion = 0;
}


CJugador::~CJugador()
{
}

void CJugador::calcular_puntacion()
{
	for (CNodo<CCarta>* i = m_lista.m_head;i; i = i->m_next)
		if (i->m_data.m_numero >= 10)
			puntuacion += 10;
		else if (i->m_data.m_numero == 8)
		{
			puntuacion += 50;
		}
		else
			puntuacion += i->m_data.m_numero;
}

void CJugador::Turno(CLista<CCarta> b, CLista<CCarta> d)
{
	cout << "Ingresa la pos ";
	int x;
	m_lista.Print();
	cout << "54.- Para sacar carta" << endl;
	cin >> x;
	if (x != 54)
	{
		CNodo<CCarta> **p;
		if (m_lista.Find(x, p))
		{
			if ((*p)->m_data.m_numero == 8)
			d.Insert(*p);
			m_lista.Remove((*p)->m_data.m_numero, (*p)->m_data.m_palo);
		}
	}
}