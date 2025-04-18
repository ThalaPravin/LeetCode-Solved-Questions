class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;  // Position to write into chars
        int i = 0;

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;

            // Count how many times currentChar repeats consecutively
            while (i < chars.size() && chars[i] == currentChar) {
                count++;
                i++;
            }

            chars[index++] = currentChar;  // Write the character

            // If count > 1, write the digits of the count
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[index++] = c;
                }
            }
        }

        return index;  // New length of compressed array
    }
};