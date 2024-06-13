class Solution {
public:
	int minMovesToSeat(vector<int>& seats, vector<int>& students) {
		int out = 0;

		// allocate students to seats
		sort(seats.begin(), seats.end());
		sort(students.begin(), students.end());

		// count number of moves
		for (int i = 0; i < seats.size(); i++) {
			out += abs(students[i] - seats[i]);
		}

		return out;
	}
};
