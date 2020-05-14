Billboard() {


   return (
      const {}
      <AnimationCycle displayIndex={Symbol()} itemCount={2}>
         <heading title='movie 1'/>
         <heading title='movie 1'/>
      </AnimationCycle>
   )
}

class AnimationCycle extends React.Component {
   componentWillReceiveProps({ displayIndex }) {
      if (this.props.displayIndex != displayIndex)
         this.cycleIndex();
   }
   getCycleIndex() {
      // cycle between 0 and 1
   }
   render() {
      const { displayIndex } = this.props;

      return React.Children.map((child, index) => {
         if (displayIndex == index) return React.clone(child)
         else return null;
      })
   }
}
