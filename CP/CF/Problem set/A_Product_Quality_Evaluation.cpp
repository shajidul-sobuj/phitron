#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n,k;
    cin >> n >> k;
    long long int count = 0;
    while(n--)
    {
        long long int x,y;
        cin >> x >> y;
        if (x*y>=k) count++;
    }
    cout << count << endl;
    return 0;
}


/*
    আপনারা সবাই এখানে well educated মানুষ। ভালো–মন্দ অবশ্যই বোঝেন।
    যাদের ভোট দেওয়ার ability ও ইচ্ছা আছে, তারা দয়া করে বুঝে–শুনে ভালো ও যোগ্য ব্যক্তিকেই ভোট দিন।

    আপনার একটি ভোট অত্যন্ত মূল্যবান।
    নির্বাচনের সময় নানা ধরনের ঝামেলা ও অনাকাঙ্ক্ষিত ঘটনা ঘটতে পারে, তাই সবাই সাবধানে থাকবেন।

    সবার প্রতি রইল আন্তরিক শুভকামনা।
*/