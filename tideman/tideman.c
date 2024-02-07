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

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void mergeSort(pair listToSort[], int leftIndex, int rightIndex);
void merge(pair listToSort[], int leftIndex, int middle, int rightIndex);

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
    printf("preferences\n");                          ///         TO DELETE
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i, ", preferences[i][j]);
        }
        printf("\n");
    }

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
        for (int l = w + 1; l < candidate_count; l++){
            preferences[ranks[w]][ranks[l]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    printf("inside add pairs\n");
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
                    printf("winner %i, loser %i => value: %i\n", i, j, preferences[i][j]);
                    pairToAdd.winner = i;
                    pairToAdd.loser = j;
                    pairs[pair_count] = pairToAdd;
                    pair_count++;
                }
            }
        }
    }
    //                                                            PRINTING TO DELETE
    for (int i = 0; i < pair_count; i++)
    {
        printf("Pair %i: %i > %i\n", i, pairs[i].winner, pairs[i].loser);
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    mergeSort(pairs, 0, pair_count - 1);
printf("\nAfter sort \n");
printf("winner %i, loser %i => value: %i\n", i, j, preferences[i][j]);

    return;
}

void mergeSort(pair listToSort[],int leftIndex, int rightIndex)
{
    if (listToSort[leftIndex] < listToSort[rightIndex])
    {
        int middle = (leftIndex + rightIndex )/2;

        mergeSort(listToSort, leftIndex, middle);
        mergeSort(listToSort, middle + 1, rightIndex);

        merge(listToSort, leftIndex, middle, rightIndex);
    }
}

void merge(pair listToSort[], int leftIndex, int middle, int rightIndex)
{
    int sizeLeftSide = middle - leftIndex + 1;
    int sizeRightSide = rightIndex - middle;

    pair leftList[sizeLeftSide];
    pair rightList[sizeRightSide];

    //fill temporary tables
    for (int i; i < sizeLeftSide; i++)
    {
        leftList[i] = listToSort[leftIndex + i];
    }
    for (int i; i < sizeRightSide; i++)
    {
        rightList[i] = listToSort[rightIndex + i]
    }

    //pointers
    int pointerLeftList = 0;
    int pointerRightList = 0;
    int pointerToFinalList = leftIndex;

    while ((pointerLeftList < sizeLeftSide) && (pointerRightList < sizeRightSide))
    {
        int valueFromLeftSide = preferences[pairs[leftList[pointerLeftList]].winner][pairs[leftList[pointerLeftList]].loser];
        int valuseFromRightSide = preferences[pairs[rightList[pointerRightList]].winner][pairs[rightList[pointerRightList]].loser];
        if (valueFromLeftSide > valuseFromRightSide)
        {
            //definetely left side has bigger value
            listToSort[pointerToFinalList] = leftList[pointerLeftList];
            pointerToFinalList++;
            pointerLeftList++;
        }
        else if (valueFromLeftSide < valuseFromRightSide)
        {
            //definetely right side has bigger value
            listToSort[pointerToFinalList] = rightList[pointerRightList];
            pointerToFinalList++;
            pointerRightList++;
        }
        else //they are equal - place them next to each other
        {
            listToSort[pointerToFinalList] = leftList[pointerLeftList];
            pointerLeftList++;
            pointerToFinalList++;

            listToSort[pointerToFinalList] = rightList[pointerRightList];
            pointerRightList++;
            pointerToFinalList++;

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

    }



}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

int sizeofArr(pair array)
{
    int size = 0;
    for ( int i = 0; i)
}
