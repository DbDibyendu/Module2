# Common programming errors
#### Memory-related bugs are among the most frightening because they often manifest themselves at a distance, in both time and space, from the source of the bug.Most of these bugs are caused by incorrect usage of pointers, hence we suggest you to not use pointers, but in cases where the system call demands the usage of pointers then the programmer should be aware of the problems that it might cause.   
![](https://qph.fs.quoracdn.net/main-qimg-b15f13f8224ed3d36b8baf9a6b449184.webp)
## Example of such errors
[![](https://mermaid.ink/img/eyJjb2RlIjoiZ3JhcGggVERcblx0QSgoQ29tbW9uIE1pc3Rha2UpKSAtLT4gQihEZXJlZmVyZW5jaW5nIEJhZCBQb2ludGVycylcbkEtLT5DKFJlYWRpbmcgVW5pbml0aWFsaXplZCBNZW1vcnkpXG5BLS0-RChBbGxvd2luZyBTdGFjayBCdWZmZXIgT3ZlcmZsb3dzKVxuQS0tPmQoTWVtb3J5IExlYWtzKVxuQS0tPmEoUmVmZXJlbmNpbmcgTm9uZXhpc3RlbnQgVmFyaWFibGVzKVxuQS0tPnkoTWlzdW5kZXJzdGFuZGluZyBQb2ludGVyIEFyaXRobWV0aWMpXG5BLS0-aShNYWtpbmcgT2ZmLWJ5LU9uZSBFcnJvcnMpXG5cblxuXHRcdFx0XHRcdCIsIm1lcm1haWQiOnsidGhlbWUiOiJkZWZhdWx0In0sInVwZGF0ZUVkaXRvciI6ZmFsc2V9)](https://mermaid-js.github.io/mermaid-live-editor/#/edit/eyJjb2RlIjoiZ3JhcGggVERcblx0QSgoQ29tbW9uIE1pc3Rha2UpKSAtLT4gQihEZXJlZmVyZW5jaW5nIEJhZCBQb2ludGVycylcbkEtLT5DKFJlYWRpbmcgVW5pbml0aWFsaXplZCBNZW1vcnkpXG5BLS0-RChBbGxvd2luZyBTdGFjayBCdWZmZXIgT3ZlcmZsb3dzKVxuQS0tPmQoTWVtb3J5IExlYWtzKVxuQS0tPmEoUmVmZXJlbmNpbmcgTm9uZXhpc3RlbnQgVmFyaWFibGVzKVxuQS0tPnkoTWlzdW5kZXJzdGFuZGluZyBQb2ludGVyIEFyaXRobWV0aWMpXG5BLS0-aShNYWtpbmcgT2ZmLWJ5LU9uZSBFcnJvcnMpXG5cblxuXHRcdFx0XHRcdCIsIm1lcm1haWQiOnsidGhlbWUiOiJkZWZhdWx0In0sInVwZGF0ZUVkaXRvciI6ZmFsc2V9)
    
## For example
### Reading Uninitialized Memory
> /* Return y = Ax */    
void matvec(int **A, int *x, int n)     
{   
    int i, j;   
    int *y = (int *)Malloc(n * sizeof(int));   
    for (i = 0; i < n; i++)  
    for (j = 0; j < n; j++)   
    y[i] += A[i][j] * x[j];   
    return;   
} 

      
In this example, the programmer has incorrectly assumed that vector y has been
initialized to zero. A correct implementation would explicitly zero y[i], or use
calloc.
