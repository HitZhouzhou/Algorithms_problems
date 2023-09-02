import itertools

# Function to calculate the total weight of edges for a given set of vertices
def total_weight(vertices, weights):
    total = 0
    for i in range(len(vertices) - 1):
        for j in range(i + 1, len(vertices)):
            total += weights[vertices[i] - 1][vertices[j] - 1]
    return total

# Read input
N = int(input())
weights = [list(map(int, input().split())) for _ in range(N)]

# Initialize the maximum total weight to 0
max_total_weight = 0

# Generate all possible pairs of vertices
all_pairs = list(itertools.combinations(range(1, N + 1), 2))

# Iterate through all possible combinations of edges
for k in range(1, N + 1):
    for vertices_combination in itertools.combinations(range(1, N + 1), k):
        # Check if the vertices in the combination form a valid matching
        valid = True
        for i in range(len(vertices_combination) - 1):
            for j in range(i + 1, len(vertices_combination)):
                if (vertices_combination[i], vertices_combination[j]) not in all_pairs:
                    valid = False
                    break
            if not valid:
                break
        
        if valid:
            # Calculate the total weight for this combination
            current_total_weight = total_weight(vertices_combination, weights)
            max_total_weight = max(max_total_weight, current_total_weight)

# Print the maximum total weight
print(max_total_weight)
