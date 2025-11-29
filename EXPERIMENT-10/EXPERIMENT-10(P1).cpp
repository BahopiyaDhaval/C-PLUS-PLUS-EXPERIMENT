#include <iostream>
#include <deque>
#include <string>
using namespace std;

struct BrowserDequeHistory {
    deque<string> hist;   // front = oldest, back = newest
    int cur = -1;         // index of current page in hist (0..hist.size()-1)

    // Visit a new page: clear forward history and push_back
    void visit(const string &url) {
        // remove everything after current
        while ((int)hist.size() - 1 > cur) hist.pop_back();
        hist.push_back(url);
        cur = (int)hist.size() - 1;
        cout << "Visited: " << url << '\n';
    }

    // Move back (if possible)
    bool back() {
        if (cur <= 0) { cout << "No previous page.\n"; return false; }
        --cur;
        cout << "Back -> " << hist[cur] << '\n';
        return true;
    }

    // Move forward (if possible)
    bool forward() {
        if (cur + 1 >= (int)hist.size()) { cout << "No forward page.\n"; return false; }
        ++cur;
        cout << "Forward -> " << hist[cur] << '\n';
        return true;
    }

    // Demonstrate adding to front (older history) — not typical from UI,
    // but useful to show deque supports push_front.
    void addOlderHistory(const string &url) {
        hist.push_front(url);
        // adjust current index to account for shift
        ++cur;
        cout << "Added older history at front: " << url << '\n';
    }

    // Peek current page
    string currentPage() const {
        if (cur < 0 || cur >= (int)hist.size()) return "(none)";
        return hist[cur];
    }

    // Print full deque and mark current
    void print() const {
        cout << "Full history (front->back): ";
        for (int i = 0; i < (int)hist.size(); ++i) {
            if (i == cur) cout << "[" << hist[i] << "] ";
            else cout << hist[i] << " ";
        }
        if (hist.empty()) cout << "(empty)";
        cout << '\n';
    }
};

int main() {
    BrowserDequeHistory bh;

    // Normal browsing
    bh.visit("google.com");
    bh.visit("openai.com");
    bh.visit("github.com");
    bh.print(); // google.com openai.com [github.com]

    // Go back twice
    bh.back();  // openai.com
    bh.back();  // google.com
    bh.print();

    // Forward once
    bh.forward(); // openai.com
    bh.print();

    // Visit a new page after going back -> forward history cleared
    bh.visit("stackoverflow.com"); // github.com removed from forward history
    bh.print();

    // Demonstrate push_front (adding an older page)
    bh.addOlderHistory("bing.com"); // now bing is oldest; current shifts right
    bh.print();

    // Demonstrate adding another newest page using push_back via visit
    bh.visit("news.ycombinator.com");
    bh.print();

    cout << "Current page: " << bh.currentPage() << '\n';

    return 0;
}


