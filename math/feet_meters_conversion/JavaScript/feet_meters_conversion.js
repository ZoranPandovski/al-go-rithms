//Converts feet to meter
const feetToMeter = (feet) => {
  return feet*0.3048;
}

//Converts meter to feet
const meterToFeet = (meter) => {
  return meter/0.3048;
}

export { feetToMeter, meterToFeet }