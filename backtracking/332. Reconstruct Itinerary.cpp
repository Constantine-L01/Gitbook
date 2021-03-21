You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Example 1:

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]

class Solution {
public:
    unordered_map<string, map<string, int>> targets;
    vector<string> result;
    int ticketNum = 0;
    
    bool backtracking() {
        if(result.size() == ticketNum){
            return true;
        }
        
        for(pair<const string, int>& target: targets[result[result.size() - 1]]){
            if(target.second > 0){
                result.push_back(target.first);
                target.second--;
                if(backtracking()) {
                    return true;
                }
                target.second++;
                result.pop_back();                
            }
        }
        return false;
    }    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ticketNum = tickets.size() + 1;
        for(vector<string> ticket: tickets){
            targets[ticket[0]][ticket[1]]++;
        }
        result.push_back("JFK");
        backtracking();
        return result;
    }
};
