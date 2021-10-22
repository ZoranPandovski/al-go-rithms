import { matrixMultiplier } from "../matrixM";

describe('Testing Matrix Multiplication', () => {
    it("Should return the correct result of the multiplication", () => {
        expect(matrixMultiplier([[1,2,3],[4,5,6]],[[10,11],[20,21],[30,31]])).toStrictEqual([[140,146],[320,335]])
    })
})
