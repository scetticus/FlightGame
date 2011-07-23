#ifndef _ARENA_H_
	#define _ARENA_H_

#include <list>
using std::list;
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "Pushable.h"
#include "Orb.h"
#include "Strand.h"

class Ship;

/// \brief Physical object container
class Arena {
	public:
		const float asize;
		list<Orb*>		Orbs;
		list<Ship*>		Ships;
		list<Strand*> 	Strands;
	
	public:
		/// \brief Constructor loads bounding model
		Arena();
		
		/// \brief Run physics updates on all objects in arena
		void Update();
		/// \brief Render physical objects
		void Render();
		
		/// \brief Register Orb into arena
		inline Orb* 	Register(Orb* _op)		{ Orbs.push_back(_op); return _op; };
		/// \brief Register Ship into arena
		inline Ship* 	Register(Ship* _op)		{ Ships.push_back(_op); return _op; };
		/// \brief Register Strand into arena
		inline Strand* 	Register(Strand* _op)	{ Strands.push_back(_op); return _op; };
		/// \brief Unegister Strand from arena
		inline Strand*  Unregister(Strand* _op) { Strands.remove(_op); return _op; };
		
		/// \brief Enact a soft elastic collision on two pushables
		/// \return Whether collision occured
		bool FluffyCollideSpheres (Pushable* sphereA, Pushable* sphereB);
		/// \brief Collide with arena walls
		/// \return Whether collision occured
		bool CollideBounds (Pushable* obj);
};

#endif
