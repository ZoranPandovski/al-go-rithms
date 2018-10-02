var doors: array[100, bool]

# Initialize doors to be closed
for i in 0..99:
  doors[i] = false

for i in 0..99:
  var j = i
  while j < 100:
    doors[j] = (not doors[j])
    j += i + 1

# Print the value of open doors
for d in 0..99:
  if doors[d]:
    echo "Door ", d + 1, " is open"
