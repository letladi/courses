module.exports = (str) => { 
  const vowels = new Set(['a', 'e', 'i', 'o', 'u'])
  const a = 'a'
  const aCode = a.charCodeAt()
  const z = 'z'
  const zCode = z.charCodeAt()
  
  const isLetter = (char) => {
    const charCode = char.charCodeAt()
    
    return aCode <= charCode && charCode <= zCode
  }
  
  const chars = str.split('')
  // code goes here  
  const modifiedChars = chars.map((c) => {
    if (isLetter(c)) {
      c = c.charCodeAt()
      c++
      c = String.fromCharCode(c)
    }
    
    if (vowels.has(c)) {
        c = c.toUpperCase()
    }
    
    return c
  })
  
  return modifiedChars.join('')
}