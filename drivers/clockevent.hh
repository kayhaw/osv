#ifndef CLOCKEVENT_HH_
#define CLOCKEVENT_HH_

#include <osv/types.h>

class clock_event_callback {
public:
    virtual ~clock_event_callback();
    // note: must always be called on the same cpu that the timer was set on
    virtual void fired() = 0;
};

class clock_event_driver {
public:
    virtual ~clock_event_driver();
    // set() is cpu-local: each processor has its own timer
    virtual void set(u64 time) = 0;
    void set_callback(clock_event_callback* callback);
    clock_event_callback* callback() const;
protected:
    clock_event_callback* _callback;

};
extern clock_event_driver* clock_event;


#endif /* CLOCKEVENT_HH_ */
