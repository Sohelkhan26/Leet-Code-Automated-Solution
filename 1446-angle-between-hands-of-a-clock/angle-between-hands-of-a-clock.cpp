class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourHand = hour * 30 + minutes * 0.5;
        double minuteHand = minutes * 6;
        double diff = abs(hourHand - minuteHand);
        return min(360.0 - diff , diff);
    }
};

/*
Hour hand depends not only on hour but also minute.
The tricky part is determining how the minute hand affects the position of the hour hand.
12 hour = 360 deg
1 hour = 30 deg

60 min = 360 deg
1 min = 6 deg

Most Crucial part:
60 min = 1 hour
1 min = 1 / 60 hour
but 1 hour = 30 deg
So, 1 min = 30 / 60 deg = 0.5 deg
So, for every 1 minute hour hand moves 0.5 deg.
Now find out total degree for hour and minute hand and find out the diff. Return the min diff. 360 - diff / diff.
*/