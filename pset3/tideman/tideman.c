#include <cs50.h>
#include <stdio.h>

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
}
pair;

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
        if (name == candidates[i])
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
    for (int i = 0; i < candidate_count; i++)
    {
        int max = candidate_count - 1;
        while (i != max)
        {
            preferences[ranks[i]][ranks[max]]++;
            max--;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int j = candidate_count;
        while (j != i)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[i].winner = i;
                pairs[i].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[i].winner = j;
                pairs[i].loser = i;
                pair_count++;
            }
            j--;
        }
        

    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++) 
    {
        //find the (i + 1)th largest no and assign it to ith_max
        int ith_max = preferences[pairs[i].winner][pairs[i].loser];
        int j = pair_count;
        
        while (j != i)
        {
            if (ith_max < preferences[pairs[j].winner][pairs[j].loser])
            {
                ith_max = preferences[pairs[j].winner][pairs[j].loser];
            }
            j--;
        }
        
        //swap ith max and ith term
        pair temp = pairs[i];
        pairs[i] = pairs[ith_max];
        pairs[ith_max] = temp;
    }  
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)//locked[i][j] means i is locked over j
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
    }
    
    for (int i = 0; i < pair_count; i++)
    {
        int counter = 0;
        for (int j = i; j < pair_count; j = (j + 1) % pair_count)
        {
            int k = j + 1;
            
            if (locked[j][k])
            {
                counter++;
            }
        }
        if (counter == pair_count - i)
        {
            
        }
    }
    
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    
    // TODO
    return;
}

