/* 
A playlist is considered a repeating playlist if any of the songs contain a pointer to a previous song in the playlist. Otherwise, the playlist will end with the last song which points to NULL.

Implement a function isRepeatingPlaylist that, efficiently with respect to time used, returns true if a playlist is repeating or false if it is not.

For example, the following code prints "true" as both songs point to each other.

Song* first = new Song("Hello");
Song* second = new Song("Eye of the tiger");
    
first->next(second);
second->next(first);

std::cout << std::boolalpha << first->isRepeatingPlaylist();
 */
#include <stdexcept>
#include <iostream>
#include <unordered_set>

class Song
{
public:
    Song(std::string name): name(name), nextSong(NULL) {}
    
    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist()
    {
        Song* tmpSong = this->nextSong;
        while (tmpSong) {
            if (tmpSong == this)
                return true;
            tmpSong = tmpSong->nextSong;
        }
        return false;
    }

    bool isRepeatingPlaylist1()
    {
        std::unordered_set<Song*> set;
        Song* tmpSong = this->nextSong;
        while (tmpSong) {
            std::unordered_set<Song*>::iterator got = set.find(tmpSong);
            if (got == set.end())
                return true;
            set.insert(tmpSong);
            tmpSong = tmpSong->nextSong;
        }
        return false;
    }

private:
    const std::string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");
    
    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isRepeatingPlaylist();
}
#endif