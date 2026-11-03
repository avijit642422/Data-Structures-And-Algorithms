#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char song[50];
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

// Add Song
void addSong()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter song name: ");
    scanf(" %[^\n]", newnode->song);

    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        current = newnode;
    }
    else
    {
        struct node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Song added successfully!\n");
}

// Display Songs
void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    printf("\nSpotify Playlist:\n");

    while(temp != NULL)
    {
        printf("%s\n", temp->song);
        temp = temp->next;
    }
}

// Play Current Song
void playSong()
{
    if(head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    printf("Now Playing: %s\n", current->song);
}

// Next Song
void nextSong()
{
    if(current == NULL)
    {
        printf("Playlist is empty!\n");
    }
    else if(current->next == NULL)
    {
        printf("No next song!\n");
    }
    else
    {
        current = current->next;
        playSong();
    }
}

// Previous Song
void previousSong()
{
    if(current == NULL)
    {
        printf("Playlist is empty!\n");
    }
    else if(current->prev == NULL)
    {
        printf("No previous song!\n");
    }
    else
    {
        current = current->prev;
        playSong();
    }
}

// Search Song
void searchSong()
{
    char name[50];
    struct node *temp = head;

    printf("Enter song name to search: ");
    scanf(" %[^\n]", name);

    while(temp != NULL)
    {
        if(strcmp(temp->song, name) == 0)
        {
            printf("Song found: %s\n", temp->song);
            return;
        }

        temp = temp->next;
    }

    printf("Song not found!\n");
}

// Delete Song
void deleteSong()
{
    char name[50];
    struct node *temp = head;

    printf("Enter song name to delete: ");
    scanf(" %[^\n]", name);

    while(temp != NULL && strcmp(temp->song, name) != 0)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Song not found!\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(current == temp)
        current = temp->next != NULL ? temp->next : temp->prev;

    free(temp);

    printf("Song deleted successfully!\n");
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n===== SPOTIFY MUSIC PLAYER =====\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Play Song\n");
        printf("4. Next Song\n");
        printf("5. Previous Song\n");
        printf("6. Search Song\n");
        printf("7. Delete Song\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addSong();
                break;

            case 2:
                display();
                break;

            case 3:
                playSong();
                break;

            case 4:
                nextSong();
                break;

            case 5:
                previousSong();
                break;

            case 6:
                searchSong();
                break;

            case 7:
                deleteSong();
                break;

            case 8:
                printf("Thank you for using Spotify!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}