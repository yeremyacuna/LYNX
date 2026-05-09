#pragma once
#include "../include/Queue.h"
#include "../include/LinkedDoubleList.h"
#include "../include/Stack.h"
#include "Trip.h"
#include "AuthManager.h"
#include <iostream>
#include <string>
using namespace std;

//   waitingQueue -> Queue<Trip>            : viajes pendientes (FIFO)
//   activeTrips  -> LinkedDoubleList<Trip> : viajes en curso
//   history      -> Stack<Trip>            : historial (ultimo viaje = top)