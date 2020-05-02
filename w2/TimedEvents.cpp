// Workshop 2 - Copy and Move Semantics
// Timekeeper.h
// 2019/01/10 - Chris Szalwinski
// 2019/09/13 - Cornel

#include <iomanip>
#include "TimedEvents.h"

namespace sdds
{
	// start timer
	//
	void TimedEvents::startClock()	{
		ts = std::chrono::steady_clock::now();
	}

	// stop timer
	//
	void TimedEvents::stopClock()
	{
		te = std::chrono::steady_clock::now();
	}

	// record an event
	//
	void TimedEvents::recordEvent(const char* msg)
	{
		auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(te - ts);
		if (nr < MAX_RECORDS)
		{
			this->events[nr].msg = msg;
			this->events[nr].units = "nanoseconds";
			this->events[nr].duration = ms;
			nr++;
		}
	}

	// report the set of times recorded
	// 
	std::ostream& operator<<(std::ostream& out, const TimedEvents& events)
	{
		out << "--------------------------\n";
		out << "Execution Times:\n";
		out << "--------------------------\n";
		for (int i = 0; i < events.nr; i++)
			out << std::setw(20) << std::left
			    << events.events[i].msg << ' ' << std::setw(12) << std::right
			    << events.events[i].duration.count() << ' '
			    << events.events[i].units << '\n';
		out << "--------------------------\n";
		return out;
	}
}