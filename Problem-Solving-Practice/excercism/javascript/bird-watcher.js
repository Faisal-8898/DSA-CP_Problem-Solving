function fixBirdCountLog(birdsPerDay) {
  // let count = 0;
  // for (let i = 0; i < birdsPerDay.length; i++){
  //   if(i%2 === 0){
  //     count++;
  //   }
  //   count += birdsPerDay[i];
  // }
  // return count;
  const newArray = birdsPerDay.map((value, index) => {
    if (index % 2 === 0) {
      value++;
    }
    return value;
  });
  return newArray;
}
const birdsPerDay = [2, 0, 1, 4, 1, 3, 0];
birdsPerDay;
