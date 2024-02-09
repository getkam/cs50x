#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

bool visited[MAX];
bool currVistited[MAX];

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void mergeSort(pair listToSort[], int leftIndex, int rightIndex);
bool checkCircle(int vertex);
void merge(pair listToSort[], int leftIndex, int middle, int rightIndex);
bool depthFirstSearch(int vertex, bool visited[]);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }
    // clear preferences
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0;
        }
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);

        printf("\n");
    }
    // printf("preferences\n");                          ///         TO DELETE
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         printf("%i, ", preferences[i][j]);
    //     }
    //     printf("\n");
    // }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0) // candidate found
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int w = 0; w < candidate_count - 1; w++)
    {
        for (int l = w + 1; l < candidate_count; l++)
        {
            preferences[ranks[w]][ranks[l]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // printf("inside add pairs\n");
    pair_count = 0;
    pair pairToAdd;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i != j)
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    //printf("winner %i, loser %i => value: %i\n", i, j, preferences[i][j]);
                    pairToAdd.winner = i;
                    pairToAdd.loser = j;
                    pairs[pair_count] = pairToAdd;
                    pair_count++;
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    mergeSort(pairs, 0, pair_count - 1);

    // printf("\nAfter sort, pair count %i\n", pair_count);
    // for (int i = 0; i < pair_count; i++)
    // {
    //         //printf("winner %i, loser %i => value: %i\n", pairs[i].winner, pairs[i].loser,
    //         preferences[pairs[i].winner][pairs[i].loser]);
    // }

    return;
}

void mergeSort(pair listToSort[], int leftIndex, int rightIndex)
{
    // printf("merge Sort: leftIndex: %i, rightIndex: %i, ", leftIndex, rightIndex);
    if (leftIndex < rightIndex)
    {
        int middle = (leftIndex + rightIndex) / 2;
        // printf("middle: %i\n",middle);

        mergeSort(listToSort, leftIndex, middle);
        mergeSort(listToSort, middle + 1, rightIndex);

        merge(listToSort, leftIndex, middle, rightIndex);
    }
    // printf("\n");
}

void merge(pair listToSort[], int leftIndex, int middle, int rightIndex)
{

    int sizeLeftSide = middle - leftIndex + 1;
    int sizeRightSide = rightIndex - middle;
    // printf("sizeLeftSide %i\n", sizeLeftSide);
    // printf("sizeRightSide %i\n", sizeRightSide);

    pair leftList[sizeLeftSide];
    pair rightList[sizeRightSide];

    // fill temporary tables
    for (int i = 0; i < sizeLeftSide; i++)
    {
        leftList[i] = listToSort[leftIndex + i];
    }
    for (int i = 0; i < sizeRightSide; i++)
    {
        rightList[i] = listToSort[middle + 1 + i];
    }

    // pointers
    int pointerLeftList = 0;
    int pointerRightList = 0;
    int pointerToFinalList = leftIndex;
    while ((pointerLeftList < sizeLeftSide) && (pointerRightList < sizeRightSide))
    {
        int valueFromLeftSide = preferences[leftList[pointerLeftList].winner][leftList[pointerLeftList].loser];
        int valueFromRightSide = preferences[rightList[pointerRightList].winner][rightList[pointerRightList].loser];
        if (valueFromLeftSide >= valueFromRightSide)
        {
            // definetely left side has bigger value
            listToSort[pointerToFinalList] = leftList[pointerLeftList];

            pointerToFinalList++;
            pointerLeftList++;
        }
        else if (valueFromLeftSide < valueFromRightSide)
        {
            // definetely right side has bigger value
            listToSort[pointerToFinalList] = rightList[pointerRightList];
            pointerToFinalList++;
            pointerRightList++;
        }
    }
    while (pointerLeftList < sizeLeftSide)
    {
        listToSort[pointerToFinalList] = leftList[pointerLeftList];
        pointerLeftList++;
        pointerToFinalList++;
    }

    while (pointerRightList < sizeRightSide)
    {
        listToSort[pointerToFinalList] = rightList[pointerRightList];
        pointerRightList++;
        pointerToFinalList++;
    }
    // printf("I T E R A T I O N\n");
    // printf("LEFT\n");
    // for (int i = 0; i < sizeLeftSide; i++)
    // {
    //         printf("winner %i, loser %i => value: %i\n", leftList[i].winner, leftList[i].loser,
    //         preferences[leftList[i].winner][leftList[i].loser]);
    // }
    // printf("RIGHT\n");
    // for (int i = 0 ; i < sizeRightSide; i++)
    // {
    //         printf("winner %i, loser %i => value: %i\n", rightList[i].winner, rightList[i].loser,
    //         preferences[rightList[i].winner][rightList[i].loser]);
    // }
    // printf("RESULT\n");
    // for (int i = leftIndex; i <= rightIndex; i++)
    // {
    //         printf("winner %i, loser %i => value: %i\n", pairs[i].winner, pairs[i].loser,
    //         preferences[pairs[i].winner][pairs[i].loser]);
    // }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int p = 0; p < pair_count; p++)
    {

        locked[pairs[p].winner][pairs[p].loser] = true;
        if (checkCircle(p))
        {
            printf("checkCircle: true\n");
            locked[pairs[p].winner][pairs[p].loser] = false;
        }
        else
        {
            printf("checkCircle: false\n");
        }
    }


    printf("LOCKED\n");
    for (int j = 0; j < candidate_count; j++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            printf("%d ",locked[i][j]);
        }
        printf("\n");
    }

    return;
}

bool checkCircle(int pairNo)
{
    for (int i = 0; i < candidate_count; i++)
    {
        visited[i] = false;
    }

    return depthFirstSearch(pairs[pairNo].winner, visited);

}

bool depthFirstSearch(int vertex, bool visited[])
{
    printf("Wierzcholek  odwiedzony: %i \n", vertex);
    if(visited[vertex])
    {
        return true;
    }
    visited[vertex] = true;

    for (int j = 0; j < candidate_count; j++)
    {
        printf("wartosc locked[vertex][j] :  %d \n", locked[vertex][j]);
        if (locked[vertex][j] && depthFirstSearch(j, visited))// next vertex
        {
                return true;
        }
    }

    return false;
}

// Print the winner of the election
void print_winner(void)
{
    for (int c = 0; c < candidate_count; c++)
    {
        if (visited[c] == false)
        {
            //printf("c: %i\n", c);
            //check if this candidate is pointing at someone
            for (int i = 0; i < candidate_count; i++)
            {
               // printf("%d ", locked[i][c]);
                if (locked[i][c] == true)
                {
                    printf("%s\n", candidates[c]);
                    return;
                }
            }
            //printf("\n");
        }
    }
    return;
}
