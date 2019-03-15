const plays = require('./plays.json')
const invoices = require('./invoices.json')

const invoice = invoices[0]

console.log(statement(invoice, plays))

function statement(invoice, plays) {
  const statementData = {
    customer: invoice.customer,
    performances: invoice.performances,
  };
  return renderPlainText(statementData, invoice, plays);
}

function renderPlainText(data, plays) {
  let result = `Statement for ${data.customer}\n`;
  for (let perf of data.performances) {
    // print line for this order
    result += `  ${playFor(perf).name}: ${usd(amountFor(perf))} (${perf.audience} seats)\n`;
  }

  result += `Amount owed is ${usd(totalAmount())}\n`;
  result += `You earned ${totalVolumeCredits()} credits\n`;
  return result;
}

function totalAmount() {
  let result = 0;
  for (let perf of invoice.performances) {
    result += amountFor(perf);
  }
  return result;
}

function volumeCreditsFor(aPerfomance) {
  let result = 0;
  result += Math.max(aPerfomance.audience - 30, 0);
  if ("comedy" === playFor(aPerfomance).type) result += Math.floor(aPerfomance.audience / 5);
  return result;
}

function usd(aNumber) {
  return new Intl.NumberFormat("en-US", { style: "currency", currency: "USD",
    minimumFractionDigits: 2 }).format(aNumber / 100);
}

function totalVolumeCredits() {
  let volumeCredits = 0;
  for (let perf of invoice.performances) {
    volumeCredits += volumeCreditsFor(perf);
  }
  return volumeCredits;
}

function amountFor(aPerfomance) {
  let amt = 0;
  switch (playFor(aPerfomance).type) {
  case "tragedy":
    amt = 40000;
    if (aPerfomance.audience > 30) {
      amt += 1000 * (aPerfomance.audience - 30);
    }
    break;
  case "comedy":
    amt = 30000;
    if (aPerfomance.audience > 20) {
      amt += 10000 + 500 * (aPerfomance.audience - 20);
    }
    amt += 300 * aPerfomance.audience;
    break;
  default:
      throw new Error(`unknown type: ${playFor(aPerfomance).type}`);
  }
  return amt;
}

function playFor(aPerfomance) {
  return plays[aPerfomance.playID]
}
