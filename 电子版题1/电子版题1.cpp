#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int hour, min;
	//input hour & min
    while(1){
        cin>>hour>>min;
        if (hour != 0 || min != 0){
            float aofh, aofm, result;//angle of hour and minute
            aofm = (float(min) / 60) * 360;
            aofh = (hour%12) * 30 + 30 * float(min) / 60;
            result = aofh - aofm;
            if (result < 0){ result = -result; };
            while (result > 180){
                result = 360 - result;
            }
            cout << "At " << hour << ":";
            cout << setw(2) << setfill('0') << min;
            cout << " the angle is ";
            cout << setiosflags(ios::fixed) << setprecision(1) << result;
            cout << " degrees." << endl;
        }
        else break;
    }
    return 0;
}
