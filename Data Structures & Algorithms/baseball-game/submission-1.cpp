class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        int total{};
        std::vector<int> record;
        record.reserve(operations.size());
        for (const auto& element : operations) {
            if (element == "+") {
                int new_score = record.back() + record[record.size() - 2];
                total += new_score;
                record.emplace_back(new_score);
            } else if (element == "D") {
                int new_score = record.back() * 2;
                total += new_score;
                record.emplace_back(new_score);
            } else if (element == "C") {

                total -= record.back();
                record.pop_back();
            } else {
                int number = std::stoi(element);
                total += number;
                record.emplace_back(number);
            }
        }
        return total;
    }
};
