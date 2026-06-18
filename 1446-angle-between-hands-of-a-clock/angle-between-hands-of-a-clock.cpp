class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        // min hand = 1 hour = 1 round = 360 degree;
        // 60 min = 360 degree;
        // 1 min = 6 degree;

        // hour hand = 1 hour = 30 degree;
        // 60 min = 30 degree;
        // 1 min = .5 degree;

        // 30 min = 180 degree; 
        // 30 min = 15 degree;
        if(hour == 12)
            hour = 0;

        double minuteAngle = minutes * 6.0;
        double hourAngle = hour * 30.0 + minutes * 0.5;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);

        // double hr = 0.5;
        // int min = 6;

        // double ans = minutes*min - hour*hr;


    }
};