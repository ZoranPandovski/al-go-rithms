/**
 * Interpolates a given number between two points.
 * With coordinates, in inputRange is the x-coordinate of the two points and outputRange is the
 * y-coordinate
 *
 * @param {number} inputRangeStart
 * @param {number} inputRangeEnd
 * @param {number} outputRangeStart
 * @param {number} outputRangeEnd
 * @param {number} valueToConvertFromInputToOutput
 */
function interpolate(
  inputRangeStart,
  inputRangeEnd,
  outputRangeStart,
  outputRangeEnd,
  valueToConvertFromInputToOutput
) {
  const inputRange = inputRangeEnd - inputRangeStart;
  const outputRange = outputRangeEnd - outputRangeStart;

  const relativeInputPosition = (valueToConvertFromInputToOutput - inputRangeStart) / inputRange;
  const absoluteOutputPosition = outputRangeStart + outputRange * relativeInputPosition;

  return absoluteOutputPosition;
}

module.exports = interpolate;
