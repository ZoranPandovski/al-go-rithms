def FractionalKnapsack(capacity, values, weights):
    rel_value = [val / weight for val, weight in zip(values, weights)]
    sorted_items = [i for _,i in sorted(zip(rel_value, range(len(rel_value))))]
    carry_items = []
    while capacity > 0 and len(sorted_items) > 0:
        item = sorted_items.pop(0)
        weight = weights[item]
        new_capacity = capacity - weight
        if new_capacity >= 0:
            carry_items.append((item, 1))
        else:
            carry_items.append((item, capacity / weight))
        capacity = new_capacity
    return carry_items

# Example execution:
# FractionalKnapsack(5, [55,2,3], [4, 1, 1])
# Returns a list like [(item_number, proportion_of_item),...]
