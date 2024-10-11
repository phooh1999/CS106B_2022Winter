# Assignment 3. Recursion!
## Part Three: What Are YOU Doing?

``` cpp
void processSentence(const Vector<string> &sentence, string sum, size_t index, Set<string> &collect) {
    if (index >= sentence.size()) {
        collect.add(sum);
        return;
    }

    string checkWord = sentence[index];
    if (!isalpha(checkWord[0])) {
        processSentence(sentence, sum + checkWord, index + 1, collect);
        return;
    }
    processSentence(sentence, sum + toUpperCase(checkWord), index + 1, collect);
    processSentence(sentence, sum + toLowerCase(checkWord), index + 1, collect);
}
```
tree recursion 处理流程：

1. 输入参数：需要处理的材料、当前已经处理完成的结果、当前已经处理的材料、如果需要所有的结果则需要一个结果集合
2. base case：如果已经处理完成，则加入结果集合
3. 创建下一步可能出现的所有结果
4. 对于每一个可能出现的结果，都递归处理
5. 有些情况可以剪枝处理

## Part Four: Shift Scheduling

递归一步只处理一个对象，对于该对象的处理可能有不同的分支，再递归处理这些分支。注意只有可能在处理分支这里出现循环和多种情况，不可能在前面拿出对象的时候，出现循环和多种处理。

这里就犯了一个错误，把拿出对象和对象的分支处理混淆了，出现大量的重复处理
```cpp
// wrong!!!
for (const Shift &shift : todoShifts) {...}

// right!!!
Shift shift = todoShifts.first();
```

```cpp
void searchScheduleRec(Set<Shift> workShifts, Set<Shift> todoShifts, int sumHours, int sumValue,
                       int maxHours, int &maxValue, Set<Shift> &resultShifts) {
    if (sumHours > maxHours) {
        return;
    }

    if (sumValue > maxValue) {
        maxValue = sumValue;
        resultShifts = workShifts;
    }

    if (todoShifts.isEmpty()) {
        return;
    }
    Shift shift = todoShifts.first();
    if (!overlaps(shift, workShifts)) {
        searchScheduleRec(workShifts + shift, todoShifts - shift, sumHours + lengthOf(shift), sumValue + valueOf(shift),
                          maxHours, maxValue, resultShifts);
    }
    searchScheduleRec(workShifts, todoShifts - shift, sumHours, sumValue, maxHours, maxValue, resultShifts);
}
```