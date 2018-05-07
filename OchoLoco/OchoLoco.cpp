// OchoLoco.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "CCarta.h"
bool comparar(CJugador* jugador,int NumJugadores)
{
	for (int i = 0; i < NumJugadores; i++) {
		if (!(jugador + i)->m_lista.m_head)
			return 0;
	}
}

int main()
{
	int NumJugadores;
	cout << "Ingresa el numero de jugadores: ";
	cin >> NumJugadores;

	CJugador *jugadores = new CJugador[NumJugadores];
	for (int i = 0; i < NumJugadores; i++)
	{
		cout << "Nombre del jugador: ";
		cin >> jugadores[i].m_nombre;
	}
	CBaraja b;
	b.Repartir(jugadores, NumJugadores);
	
	CLista<CCarta> LDescarte;
	LDescarte.Insert(b.m_lista.m_head);
	b.m_lista.Pop();

	LDescarte.m_head->m_data.Print();
	do
	{
		for (int i = 0; i < NumJugadores; i++) {
			//jugadores[i].Turno(b, LDescarte);
			if (!jugadores[i].m_lista.m_head)
				return 0;
		}
	} while (b.m_size != 0 && comparar(jugadores, NumJugadores));

	return 0;
}

