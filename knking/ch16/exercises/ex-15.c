// a) ❌
struct weekday {
   SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY,
};
/**
 * enum week_days { MON, TUE, WED, THU, FRI, SAT, SUN };
 */

// b) ✔️
typedef enum { MON, TUE, WED, THU, FRI, SAT, SUN, } week_day;