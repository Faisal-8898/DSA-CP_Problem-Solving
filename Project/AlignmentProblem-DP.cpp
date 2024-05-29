#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

// Function to calculate the minimum penalty using the Needleman-Wunsch algorithm
int needleman_wunsch(const char *X, const char *Y, int p_gap, int p_mismatch, char *aligned_X, char *aligned_Y)
{
    int m = strlen(X);
    int n = strlen(Y);

    // DP table to store the penalties
    int *dp = (int *)malloc((m + 1) * sizeof(int *));
    char *direction = (char *)malloc((m + 1) * sizeof(char *));
    for (int i = 0; i <= m; ++i)
    {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
        direction[i] = (char *)malloc((n + 1) * sizeof(char));
    }

    // Initialize the DP table
    for (int i = 0; i <= m; ++i)
    {
        dp[i][0] = i * p_gap;
        direction[i][0] = 'U'; // Up, indicating a gap in Y
    }
    for (int j = 0; j <= n; ++j)
    {
        dp[0][j] = j * p_gap;
        direction[0][j] = 'L'; // Left, indicating a gap in X
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int match_or_mismatch = dp[i - 1][j - 1] + (X[i - 1] == Y[j - 1] ? 0 : p_mismatch);
            int gap_in_X = dp[i][j - 1] + p_gap;
            int gap_in_Y = dp[i - 1][j] + p_gap;

            dp[i][j] = (match_or_mismatch < gap_in_X) ? match_or_mismatch : gap_in_X;
            dp[i][j] = (dp[i][j] < gap_in_Y) ? dp[i][j] : gap_in_Y;

            if (dp[i][j] == match_or_mismatch)
            {
                direction[i][j] = 'D'; // Diagonal
            }
            else if (dp[i][j] == gap_in_X)
            {
                direction[i][j] = 'L'; // Left
            }
            else
            {
                direction[i][j] = 'U'; // Up
            }
        }
    }

    // Backtrack to find the aligned sequences
    int i = m, j = n;
    int index_X = 0, index_Y = 0;
    while (i > 0 || j > 0)
    {
        if (direction[i][j] == 'D')
        {
            aligned_X[index_X++] = X[i - 1];
            aligned_Y[index_Y++] = Y[j - 1];
            --i;
            --j;
        }
        else if (direction[i][j] == 'U')
        {
            aligned_X[index_X++] = X[i - 1];
            aligned_Y[index_Y++] = '_';
            --i;
        }
        else
        {
            aligned_X[index_X++] = '_';
            aligned_Y[index_Y++] = Y[j - 1];
            --j;
        }
    }

    // The sequences are built backwards, so reverse them
    aligned_X[index_X] = '\0';
    aligned_Y[index_Y] = '\0';
    for (int k = 0; k < index_X / 2; ++k)
    {
        char temp = aligned_X[k];
        aligned_X[k] = aligned_X[index_X - k - 1];
        aligned_X[index_X - k - 1] = temp;
    }
    for (int k = 0; k < index_Y / 2; ++k)
    {
        char temp = aligned_Y[k];
        aligned_Y[k] = aligned_Y[index_Y - k - 1];
        aligned_Y[index_Y - k - 1] = temp;
    }

    int result = dp[m][n];

    // Free allocated memory
    for (int i = 0; i <= m; ++i)
    {
        free(dp[i]);
        free(direction[i]);
    }
    free(dp);
    free(direction);

    // Return the minimum penalty
    return result;
}

// Function to calculate the local alignment using the Smith-Waterman algorithm
int smith_waterman(const char *X, const char *Y, int p_gap, int p_mismatch, char *aligned_X, char *aligned_Y)
{
    int m = strlen(X);
    int n = strlen(Y);

    // DP table to store the scores
    int *dp = (int *)malloc((m + 1) * sizeof(int *));
    char *direction = (char *)malloc((m + 1) * sizeof(char *));
    for (int i = 0; i <= m; ++i)
    {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
        direction[i] = (char *)malloc((n + 1) * sizeof(char));
    }

    // Initialize the DP table
    for (int i = 0; i <= m; ++i)
    {
        dp[i][0] = 0;
        direction[i][0] = '0';
    }
    for (int j = 0; j <= n; ++j)
    {
        dp[0][j] = 0;
        direction[0][j] = '0';
    }

    // Initialize variables to track the maximum score
    int max_i = 0, max_j = 0, max_score = 0;

    // Fill the DP table
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int match_or_mismatch = dp[i - 1][j - 1] + (X[i - 1] == Y[j - 1] ? 0 : p_mismatch);
            int gap_in_X = dp[i][j - 1] + p_gap;
            int gap_in_Y = dp[i - 1][j] + p_gap;

            dp[i][j] = 0;
            direction[i][j] = '0';

            if (match_or_mismatch > dp[i][j])
            {
                dp[i][j] = match_or_mismatch;
                direction[i][j] = 'D';
            }
            if (gap_in_X > dp[i][j])
            {
                dp[i][j] = gap_in_X;
                direction[i][j] = 'L';
            }
            if (gap_in_Y > dp[i][j])
            {
                dp[i][j] = gap_in_Y;
                direction[i][j] = 'U';
            }

            if (dp[i][j] > max_score)
            {
                max_score = dp[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    // Backtrack to find the aligned sequences from the max_score cell
    int i = max_i, j = max_j;
    int index_X = 0, index_Y = 0;
    while (i > 0 && j > 0 && dp[i][j] != 0)
    {
        if (direction[i][j] == 'D')
        {
            aligned_X[index_X++] = X[i - 1];
            aligned_Y[index_Y++] = Y[j - 1];
            --i;
            --j;
        }
        else if (direction[i][j] == 'U')
        {
            aligned_X[index_X++] = X[i - 1];
            aligned_Y[index_Y++] = '_';
            --i;
        }
        else
        {
            aligned_X[index_X++] = '_';
            aligned_Y[index_Y++] = Y[j - 1];
            --j;
        }
    }

    // The sequences are built backwards, so reverse them
    aligned_X[index_X] = '\0';
    aligned_Y[index_Y] = '\0';
    for (int k = 0; k < index_X / 2; ++k)
    {
        char temp = aligned_X[k];
        aligned_X[k] = aligned_X[index_X - k - 1];
        aligned_X[index_X - k - 1] = temp;
    }
    for (int k = 0; k < index_Y / 2; ++k)
    {
        char temp = aligned_Y[k];
        aligned_Y[k] = aligned_Y[index_Y - k - 1];
        aligned_Y[index_Y - k - 1] = temp;
    }

    int result = max_score;

    // Free allocated memory
    for (int i = 0; i <= m; ++i)
    {
        free(dp[i]);
        free(direction[i]);
    }
    free(dp);
    free(direction);

    // Return the maximum score
    return result;
}

int main()
{
    char str1[100], str2[100];
    int gap_penalty, mismatch_penalty;

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    printf("Enter gap penalty: ");
    scanf("%d", &gap_penalty);
    printf("Enter mismatch penalty: ");
    scanf("%d", &mismatch_penalty);

    char aligned_str1[200], aligned_str2[200];
    // Needleman-Wunsch
    printf("\nNeedleman-Wunsch Algorithm:\n");
    int min_penalty = needleman_wunsch(str1, str2, gap_penalty, mismatch_penalty, aligned_str1, aligned_str2);
    printf("Minimum penalty aligning two strings is: %d\n", min_penalty);
    printf("Aligned sequences:\n");
    printf("%s\n", aligned_str1);
    printf("%s\n", aligned_str2);

    // Smith-Waterman
    printf("\nSmith-Waterman Algorithm:\n");
    int max_score = smith_waterman(str1, str2, gap_penalty, mismatch_penalty, aligned_str1, aligned_str2);
    printf("Maximum score for local alignment is: %d\n", max_score);
    printf("Aligned sequences:\n");
    printf("%s\n", aligned_str1);
    printf("%s\n", aligned_str2);

    return 0;
}