// split将字符串变为数组，reduce是对数组中的所有元素调用指定的回调函数。该回调函数的返回值为累积结果，并且此返回值在下一次调用该回调函数时作为参数提供
//https://msdn.microsoft.com/zh-cn/library/ff679975(v=vs.94).aspx

const numJewelsInStones = (J, S) => {
    const jewels = new Set(J)
    return S.split('').reduce((res, s) => res + jewels.has(s), 0)
};