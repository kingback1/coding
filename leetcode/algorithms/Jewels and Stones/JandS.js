// split���ַ�����Ϊ���飬reduce�Ƕ������е�����Ԫ�ص���ָ���Ļص��������ûص������ķ���ֵΪ�ۻ���������Ҵ˷���ֵ����һ�ε��øûص�����ʱ��Ϊ�����ṩ
//https://msdn.microsoft.com/zh-cn/library/ff679975(v=vs.94).aspx

const numJewelsInStones = (J, S) => {
    const jewels = new Set(J)
    return S.split('').reduce((res, s) => res + jewels.has(s), 0)
};