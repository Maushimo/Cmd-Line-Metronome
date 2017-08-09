/*
NOTES:
BPM
Beats/60secs = Beats per second

example:
	120bpm
	120beats/60secs = 2 beats per second
	1sec = 2 beats

	200bpm
	200beats/60secs = 3.33 beats per second
*/

#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds MilliSecs;
typedef std::chrono::duration<float> FloatSecs;
/* GLOBAL VARS */
int bpm;
int CurrentCount;

int main(int argc, char const *argv[])
{
	auto Time0 = Time::now();

	for(;;)
	{
		auto Time1 = Time::now();
		FloatSecs DeltaTime = (Time1 - Time0);
		MilliSecs DeltaTimeMS = std::chrono::duration_cast<MilliSecs>(DeltaTime);
		std::cout << "Time: " << DeltaTime.count() << "s\n";
		std::cout << "Time: " << DeltaTimeMS.count() << "ms\n";
	}
	/*
	std::cout << "---------" << std::endl << "METRONOME" << std::endl << "---------" << std::endl;
	std::cout << "Specify your BPM: ";
	std::cin >> bpm;
	//std::cout << "BPM: " << bpm << std::endl;
	//std::cout << "Count: " << CurrentCount << std::endl;
	*/

	return 0;
}