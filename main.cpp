/*
NOTES [THEORY]:
BPM
Beats per minute/60secs = Beats per second
1000ms/BPS = interval

example:
	120bpm
	120beats/60secs = 2 beats per second
	1sec = 2 beats
	1000ms/2 beats = 500ms => INCREMENT COUNTER

	200bpm
	200beats/60secs = 3.33 beats per second
	1sec = 3.33 beats (rounded)
	1000ms/3 = 333ms => INCREMENT COUNTER
*/

#include <iostream>
#include <chrono>
/* TYPEDEFs */
typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds MilliSecs;
typedef std::chrono::duration<float> FloatSecs;
/* STATES */
enum class States { INPUTTING, TICKTOCK };
/* GLOBAL VARS */
int bpm = -1;
int CurrentCount = 0;
/* METHODS */
float CalculateInterval(int BeatsPerMinute);

int main(int argc, char const *argv[])
{
	//Get time at the start of the program
	auto Time0 = Time::now();

	//state machine
	States CurrentState = States::INPUTTING;

	while(CurrentState == States::INPUTTING)
	{
		std::cout << "---------" << std::endl << "METRONOME" << std::endl << "---------" << std::endl;
		std::cout << "Specify your BPM: ";
		std::cin >> bpm;

		//once bpm has been inputted start the metronome
		if(bpm > 0)
		{
			CurrentState = States::TICKTOCK;
		}
	}

	while(CurrentState == States::TICKTOCK)
	{
		//calculate the interval between counts
		float Interval = CalculateInterval(bpm);

		//some timer stuff
		auto Time1 = Time::now();
		FloatSecs DeltaTime = (Time1 - Time0);
		//convert float seconds into milliseconds
		MilliSecs dtMS = std::chrono::duration_cast<MilliSecs>(DeltaTime);
		//delta time in milliseconds
		float AccDelta = 0.0f;
		AccDelta += dtMS.count();

		if(AccDelta > Interval)
		{
			if(CurrentCount >= 4)
			{
				CurrentCount = 1;
			}
			else if(CurrentCount >= 0 && CurrentCount < 4)
			{
				CurrentCount++;
			}
			//reset timer
			Time0 = Time::now();
			AccDelta = 0.0f;
		}

		//print out some debug info and counter
		std::cout << "BPM: " << bpm << " ";
		std::cout << "Interval: " << Interval << "ms ";
		std::cout << "Time: "  << AccDelta << "ms ";
		std::cout << "Count: " << CurrentCount << "\r";
	}

	return 0;
}

float CalculateInterval(int BeatsPerMinute)
{
	float BeatsPerSecond = bpm/60.0f;
	float Interval = 1000.0f/BeatsPerSecond;
	return Interval;
}