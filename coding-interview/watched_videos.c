/* 
Implement the count_views function. It accepts an array of pointers to the Viewer struct, the size of the array, and the character array with the video name. It should return the number of Viewers who have watched a Video with the name video_name.

For example,

Video videos[] = { {.name = "Soccer", .unique_views = 500},
                   {.name = "Basketball", .unique_views = 1000} };
Viewer viewer = {.username = "Dave", .watched_videos = videos,
                 .watched_videos_size = 2};    
Viewer *viewers[] = { &viewer };

calling count_views(viewers, 1, "Soccer") should return 1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Video {
    char *name;
    int unique_views;
} Video;

typedef struct Viewer {
    char *username;
    Video *watched_videos;
    int watched_videos_size;
} Viewer;

int count_views(Viewer **viewers, int viewers_size, char *video_name)
{
    unsigned int count = 0;
    for (unsigned int i = 0; i < viewers_size; i++) {
        for (unsigned int j = 0; j < (*viewers)->watched_videos_size; j++) {
            if (!strcmp((*viewers)->watched_videos->name, video_name))
                count++;
            (*viewers)->watched_videos++;
        }
        viewers++;
    }
    return count;
}

#ifndef RunTests
int main() {
    Video videos1[] = { {.name = "Soccer", .unique_views = 500},
                       {.name = "Basketball", .unique_views = 1000} };
    Viewer viewer1 = {.username = "Dave", .watched_videos = videos1,
                     .watched_videos_size = 2};

    Video videos2[] = { {.name = "Soccer", .unique_views = 500},
                       {.name = "Basketball", .unique_views = 1000} };
    Viewer viewer2 = {.username = "Mari", .watched_videos = videos2,
                     .watched_videos_size = 2};

    Video videos3[] = { {.name = "Football", .unique_views = 500},
                       {.name = "Basketball", .unique_views = 1000},
                       {.name = "Badminton", .unique_views = 1000} };
    Viewer viewer3 = {.username = "Peter", .watched_videos = videos3,
                     .watched_videos_size = 3};

    Video videos4[] = {};
    Viewer viewer4 = {.username = "Michael", .watched_videos = videos4,
                     .watched_videos_size = 0};
    
    // Viewer *viewers[] = { &viewer1, &viewer2, &viewer3, &viewer4};
    Viewer *viewers[] = { &viewer4};
    printf("%d\n", count_views(viewers, 1, "Badminton"));
}
#endif