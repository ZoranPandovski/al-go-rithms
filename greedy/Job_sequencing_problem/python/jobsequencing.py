class Job:
    def __init__(self, name, deadline, duration, profit):
        self.name = name
        self.deadline = deadline
        self.duration = duration
        self.profit = profit

    def __lt__(self, other):
        return self.profit < other.profit

    def __str__(self):
        return self.name

# Greedy algorithm
def JobSequencing(jobs, time_slots):
    jobs = sorted(jobs)
    sequence = [jobs.pop()]
    while len(jobs) > 0 and sum([j.duration for j in sequence]) < time_slots:
        job = jobs.pop()
        finish_time = sum([j.duration for j in sequence]) + job.duration
        if finish_time < time_slots and finish_time < job.deadline:
            sequence.append(job)
    return sequence

# Example execution
# jobs = [Job('a', 3, 1, 2), Job('b', 2, 2, 5), Job('c', 4, 1,3)]
# print([str(j) for j in JobSequencing(jobs, 3)])
